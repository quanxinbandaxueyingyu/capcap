#include "stdafx.h"
#include <stdint.h>
#include <cstdlib>
struct PcapHeader{
	uint32_t magic; // 0x1A 2B 3C 4D标示文件的开始
	uint16_t major; // 0x02 00: 当前文件主要的版本号
	uint16_t minor; // 0x04 00:当前文件次要的版本号
	uint32_t thisZone; // 当地的标准时间；全零
	uint32_t sigFigs; // 时间戳的精度；全零
	uint32_t snapLen; // 最大的存储长度
	uint32_t linkType; // 链路类型
}PcapHeader;

struct PackageHeader{
	uint32_t timeStampH; // 时间戳高位，精确到seconds
	uint32_t timeStampL; // 时间戳低位，精确到microseconds
	uint32_t capLen; // 当前数据区的长度，即抓取到的数据帧长度，由此可以得到下一个数据帧的位置
	uint32_t len; // 离线数据长度：网络中实际数据帧的产犊，一般不大于caplen，多数情况下和caplen数值相等。
}PackageHeader;


typedef struct MacAddr{
	uint8_t bytes[6];
}MacAddr;

// Ethernet 首部
typedef struct EthernetHeader 
{
	MacAddr dmac;
	MacAddr smac;
	uint16_t	type;		// (16 bits)注意用的时候大端转换为小端！
}EthernetHeader;


// IPv4 首部
typedef struct IpHeader{
	uint8_t  versionAndHeadLen;        // 版本 (4 bits) + 首部长度 (4 bits)
	uint8_t  typeOfService;            // 服务类型(Type of service) 
	uint16_t totalLen;           // 总长(Total length) 
	uint16_t identification; // 标识(Identification)
	uint16_t flagsAndFragmentOffset;       // 标志位(Flags) (3 bits) + 段偏移量(Fragment offset) (13 bits)		，intel使用小端模式
	uint8_t  timeToLive;            // 存活时间(Time to live)
	uint8_t  proto;          // 协议(Protocol)
	uint16_t HeaderChecksum;            // 首部校验和(Header checksum)
	uint32_t srcIp;      // 源地址(Source address)
	uint32_t desIp;      // 目的地址(Destination address)
	uint32_t optionAndPadding;         // 选项与填充(Option + Padding)
}IpHeader;

// TCP

// UDP 首部
typedef struct UdpHeader{
	uint16_t sport;          // 源端口(Source port)		      Winsock 内置函数 ntohs（），主要作用将大端转换为小端！
	uint16_t dport;          // 目的端口(Destination port)	  Winsock 内置函数 ntohs（），主要作用将大端转换为小端！
	uint16_t len;            // UDP数据包长度(Datagram length)
	uint16_t crc;            // 校验和(Checksum)
}UdpHeader;


// TCP首部
typedef struct TcpHeader{
	uint16_t  srcPort;       // (16 bits)						 Winsock 内置函数 ntohs（），主要作用将大端转换为小端！
	uint16_t  desPort;  // (16 bits)						 Winsock 内置函数 ntohs（），主要作用将大端转换为小端！
	uint32_t seqNumber;        // Sequence Number (32 bits)		 大小端原因，高低位4个8bit的存放顺序是反的，intel使用小端模式
	uint32_t ackNumber;        // Acknowledgment Number (32 bits)	 大小端原因，高低位4个8bit的存放顺序是反的，intel使用小端模式
	uint16_t  infoCtrl;         // Data Offset (4 bits), Reserved (6 bits), Control bits (6 bits)				intel使用小端模式
	uint16_t  window;            // (16 bits)
	uint16_t  checksum;          // (16 bits)
	uint16_t  urgentPointer;    // (16 bits)
} TcpHeader;
