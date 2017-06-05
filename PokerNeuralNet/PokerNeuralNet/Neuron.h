#pragma once
#include <vector>

using namespace std;
class Neuron;

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

