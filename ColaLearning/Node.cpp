#include "Node.h"


Node::Node(vector<double> node_Values)
{
	nodeValues = node_Values;
}

double Node::GetNodeValue(int n)
{
	if (n < 0)
	{
		printf("Error : %d번째 인자를 선택하였습니다.\n", n);
		return 0;
	}
	return nodeValues[n];
}