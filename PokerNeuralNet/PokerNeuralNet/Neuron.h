#pragma once
#include <vector>

using namespace std;

typedef vector<Neuron> Layer;

struct Connection
{
	double weight;
	double deltaWeight;
};

class Neuron
{
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void feedForward(const Layer &prevLayer);
	void setOutputVal(double val) { m_outputVal = val; }
	double getOutputVal(void) const { return m_outputVal; }
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer);
	~Neuron();
private:
	static double randomWeight(void);
	static double activationFunction(double x);
	static double activationFunctionDerivative(double x);
	static double eta;
	static double alpha ;
	double sumDOW(const Layer &nextLayer);
	unsigned m_myIndex;
	double m_outputVal;
	double m_gradient;
	vector<Connection> m_outputWeights;
};

double Neuron::eta = 0.15; // overall net learning rate, [0.0...1.0]
double Neuron::alpha = 0.5; // momentum, multiplier of last deltaweight, [0.0...n]