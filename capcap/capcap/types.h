#include "stdafx.h"
#include <stdint.h>
#include <cstdlib>
struct PcapHeader{
	uint32_t magic; // 0x1A 2B 3C 4D��ʾ�ļ��Ŀ�ʼ
	uint16_t major; // 0x02 00: ��ǰ�ļ���Ҫ�İ汾��
	uint16_t minor; // 0x04 00:��ǰ�ļ���Ҫ�İ汾��
	uint32_t thisZone; // ���صı�׼ʱ�䣻ȫ��
	uint32_t sigFigs; // ʱ����ľ��ȣ�ȫ��
	uint32_t snapLen; // ���Ĵ洢����
	uint32_t linkType; // ��·����
}PcapHeader;

struct PackageHeader{
	uint32_t timeStampH; // ʱ�����λ����ȷ��seconds
	uint32_t timeStampL; // ʱ�����λ����ȷ��microseconds
	uint32_t capLen; // ��ǰ�������ĳ��ȣ���ץȡ��������֡���ȣ��ɴ˿��Եõ���һ������֡��λ��
	uint32_t len; // �������ݳ��ȣ�������ʵ������֡�Ĳ�����һ�㲻����caplen����������º�caplen��ֵ��ȡ�
}PackageHeader;


typedef struct MacAddr{
	uint8_t bytes[6];
}MacAddr;

// Ethernet �ײ�
typedef struct EthernetHeader 
{
	MacAddr dmac;
	MacAddr smac;
	uint16_t	type;		// (16 bits)ע���õ�ʱ����ת��ΪС�ˣ�
}EthernetHeader;


// IPv4 �ײ�
typedef struct IpHeader{
	uint8_t  versionAndHeadLen;        // �汾 (4 bits) + �ײ����� (4 bits)
	uint8_t  typeOfService;            // ��������(Type of service) 
	uint16_t totalLen;           // �ܳ�(Total length) 
	uint16_t identification; // ��ʶ(Identification)
	uint16_t flagsAndFragmentOffset;       // ��־λ(Flags) (3 bits) + ��ƫ����(Fragment offset) (13 bits)		��intelʹ��С��ģʽ
	uint8_t  timeToLive;            // ���ʱ��(Time to live)
	uint8_t  proto;          // Э��(Protocol)
	uint16_t HeaderChecksum;            // �ײ�У���(Header checksum)
	uint32_t srcIp;      // Դ��ַ(Source address)
	uint32_t desIp;      // Ŀ�ĵ�ַ(Destination address)
	uint32_t optionAndPadding;         // ѡ�������(Option + Padding)
}IpHeader;

// TCP

// UDP �ײ�
typedef struct UdpHeader{
	uint16_t sport;          // Դ�˿�(Source port)		      Winsock ���ú��� ntohs��������Ҫ���ý����ת��ΪС�ˣ�
	uint16_t dport;          // Ŀ�Ķ˿�(Destination port)	  Winsock ���ú��� ntohs��������Ҫ���ý����ת��ΪС�ˣ�
	uint16_t len;            // UDP���ݰ�����(Datagram length)
	uint16_t crc;            // У���(Checksum)
}UdpHeader;


// TCP�ײ�
typedef struct TcpHeader{
	uint16_t  srcPort;       // (16 bits)						 Winsock ���ú��� ntohs��������Ҫ���ý����ת��ΪС�ˣ�
	uint16_t  desPort;  // (16 bits)						 Winsock ���ú��� ntohs��������Ҫ���ý����ת��ΪС�ˣ�
	uint32_t seqNumber;        // Sequence Number (32 bits)		 ��С��ԭ�򣬸ߵ�λ4��8bit�Ĵ��˳���Ƿ��ģ�intelʹ��С��ģʽ
	uint32_t ackNumber;        // Acknowledgment Number (32 bits)	 ��С��ԭ�򣬸ߵ�λ4��8bit�Ĵ��˳���Ƿ��ģ�intelʹ��С��ģʽ
	uint16_t  infoCtrl;         // Data Offset (4 bits), Reserved (6 bits), Control bits (6 bits)				intelʹ��С��ģʽ
	uint16_t  window;            // (16 bits)
	uint16_t  checksum;          // (16 bits)
	uint16_t  urgentPointer;    // (16 bits)
} TcpHeader;
