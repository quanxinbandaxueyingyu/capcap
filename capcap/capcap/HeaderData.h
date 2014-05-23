#pragma once
class HeaderData
{
private:
	int len;
	char *data;
public:
	HeaderData(void);
	HeaderData(char *src, int len);
	~HeaderData(void);
};

