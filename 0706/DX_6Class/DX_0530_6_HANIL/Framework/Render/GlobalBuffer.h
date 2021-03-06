#pragma once

inline void IASetPT(D3D_PRIMITIVE_TOPOLOGY type = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
{
	DEVICE_CONTEXT->IASetPrimitiveTopology(type);
}

class MatrixBuffer : public ConstantBuffer
{
	struct Data
	{
		XMMATRIX _matrix;
	};
public:
	MatrixBuffer()
	: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._matrix = XMMatrixIdentity();
	}

	void Set(XMMATRIX value)
	{
		_data._matrix = XMMatrixTranspose(value);
	}

private:
	Data _data;
};

class ColorBuffer : public ConstantBuffer
{
	struct Data
	{
		XMFLOAT4 _color;
	};
public:
	ColorBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._color = { 1,1,1,1 };
	}

	void SetColor(const XMFLOAT4& color)
	{
		_data._color = color;
	}

private:
	Data _data;
};

class FrameBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 _maxFrame;
		XMFLOAT2 _curFrame;
	}_data;

	FrameBuffer()
	: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._maxFrame = { 1,1 };
		_data._curFrame = { 1,1 };
	}
};

class ActionBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		// 16바이트씩 끊어서 읽는다.. => 16바이트의 정수배로 정보를 줘야함.
		Vector2 _startPos;
		Vector2 _maxSize;
		Vector2 _size;
		Vector2 padding;
	}_data;
	
	ActionBuffer()
	: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._startPos = { 0,0 };
		_data._maxSize = { 0,0 };
		_data._size = { 0,0 };
		_data.padding = { 0,0 };
	}

};