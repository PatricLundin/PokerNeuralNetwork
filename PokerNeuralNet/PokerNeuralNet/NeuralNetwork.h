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

