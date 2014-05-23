#include "StdAfx.h"
#include "HeaderData.h"


HeaderData::HeaderData(char *src, int len){
	this->len = len;
	this->data = new char[len];
	memcpy(this->data, src, len);
}

HeaderData::HeaderData(void)
{
}


HeaderData::~HeaderData(void)
{
	delete this->data;
}
