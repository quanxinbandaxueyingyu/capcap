#pragma once
class CapData
{
private:
	int readed;
	int total;
public:
	CapData(void);
	~CapData(void);
	int LoadFile(char*s);
	int GetTotalSize();
	int ReadPcapHeader();
	int ReadIpHeader();
	int ReadTCPHeader();
	int ReadHTTPHeader();
	int ReadText();
};

