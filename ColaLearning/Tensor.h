#pragma once
#include <vector>
using namespace std;


class Tensor
{
public:
	Tensor() { x = 0; y = 0; channel = 0; bias = false; }
	Tensor(int _x, int _y = 0, int _channel = 0, bool _bias = false) { x = _x; y = _y; channel = _channel; bias = _bias; }

	bool operator<(const Tensor& rhs) const;
	bool operator!=(const Tensor& rhs) const;
	bool operator==(const Tensor& rhs) const;
	Tensor operator+(const Tensor& rhs) const;
	void operator+=(const Tensor& rhs);
	bool CheckBias() const;
	/**
	 * ���� �ټ� ��������.
	 * 
	 * \param channel : ä��
	 * \return ���� �ټ�
	 */
	static Tensor GetBias();
	vector<int> GetXYChannel() const;
	vector<int> GetXYChannelSize() const;
	vector<Tensor> GetTensors() const;

private:
	int x;
	int y;
	int channel;
	// ������ ����ġ������ ���
	bool bias;
};

class TensorConnection
{
public:
	TensorConnection(Tensor _previous, Tensor _next) { previous = _previous; next = _next; }

	bool operator<(const TensorConnection& rhs) const;
	/**
	 * ���� �� �ټ� ��������.
	 * 
	 * \return ���� �� �ټ�
	 */
	Tensor GetPrevious() const;
	/**
	 * ���� �� �ټ� ��������.
	 * 
	 * \return ���� �� �ټ�
	 */
	Tensor GetNext() const;

private:
	Tensor previous;
	Tensor next;
};
