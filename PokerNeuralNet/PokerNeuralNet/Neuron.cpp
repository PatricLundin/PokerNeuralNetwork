#include "Neuron.h"
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	m_myIndex = myIndex;
	for (unsigned c = 0; c < numOutputs; ++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
	cout << "I was created wohoo" << endl;
}

void Neuron::feedForward(const Layer & prevLayer)
{
	double sum = 0.0;

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::activationFunction(sum);
}

double Neuron::randomWeight(void)
{
	return rand() / double(RAND_MAX);
}

double Neuron::activationFunction(double x)
{
	return 1 / (1 + exp(-x));
}

double Neuron::activationFunctionDerivative(double x)
{
	return Neuron::activationFunction(x) * (1 - Neuron::activationFunction(x));
}

double Neuron::sumDOW(const Layer & nextLayer)
{
	double sum = 0.0;

	for (unsigned n = 0; n < nextLayer.size() - 1; ++n) {
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}
	return sum;
}

void Neuron::calcOutputGradients(double targetVal)
{
	double delta = targetVal - m_outputVal;
	m_gradient = delta * Neuron::activationFunctionDerivative(m_outputVal);
}

void Neuron::calcHiddenGradients(Layer &nextLayer)
{
	double dow = sumDOW(nextLayer);
	m_gradient = dow * Neuron::activationFunctionDerivative(m_outputVal);
}

void Neuron::updateInputWeights(Layer &prevLayer)
{
	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight = eta * neuron.getOutputVal() * m_gradient * alpha * oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}

Neuron::~Neuron()
{
}
