#pragma once

#include <vector>
#include "Neuron.h"

using namespace std;


class NeuralNetwork
{
public:
	NeuralNetwork(const vector<unsigned> &topology);
	~NeuralNetwork();
	void feedForward(const vector<double> &inputVals);
	void backProp(const vector<double> &targetVals);
	void getResults(vector<double> &resultVals) const;
private:
	vector<Layer> m_layers;
	double m_error;
	double m_recentAverageSmootingFactor;
	double m_recentAverageError;
};

double Neuron::eta = 0.15; // overall net learning rate, [0.0...1.0]
double Neuron::alpha = 0.5; // momentum, multiplier of last deltaweight, [0.0...n]