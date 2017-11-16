#ifndef _TIME_H_
#define _TIME_H_

#include "Define.h"

namespace Avalon
{
	/**
	*@brief ʱ���࣬��ȷ������
	*/
	class Time
	{
	public:
		//ÿ�������
		const static UInt32 MSECS_OF_SEC = 1000;
		//ÿ������
		const static UInt32 SECS_OF_MIN = 60;
		//ÿСʱ����
		const static UInt32 SECS_OF_HOUR = (60 * SECS_OF_MIN);
		//ÿ������
		const static UInt32 SECS_OF_DAY = (24 * SECS_OF_HOUR);
		//ÿ�պ�����
		const static UInt32 MSECS_OF_DAY = (SECS_OF_DAY * MSECS_OF_SEC);

	public:
		Time() :m_MilliSecond(0){}
		Time(UInt64 msec) :m_MilliSecond(msec){}
		Time(const Time& time) :m_MilliSecond(time.m_MilliSecond){}
		~Time(){}

	public:
		/**
		*@brief ��ȡ��ǰʱ��
		*/
		static Time CurrentTime();

		/**
		*@brief ��ȡ������
		*/
		UInt64 MSec() const{ return m_MilliSecond; }

		/**
		*@brief ��ȡ����
		*/
		UInt64 Sec() const { return m_MilliSecond / 1000; }

		//�߼�����������
		bool operator<(const Time& time) const{ return m_MilliSecond < time.m_MilliSecond; }
		bool operator>(const Time& time) const{ return m_MilliSecond > time.m_MilliSecond; }
		bool operator>=(const Time& time) const{ return !operator<(time); }
		bool operator<=(const Time& time) const{ return !operator>(time); }

		bool operator==(const Time& time) const { return m_MilliSecond == time.m_MilliSecond; }
		bool operator!=(const Time& time) const{ return !operator==(time); }

		//��������������
		friend const Time operator+ (const Time&, const Time&);
		friend const Time operator- (const Time&, const Time&);

		const Time& operator+= (const Time& time)
		{
			m_MilliSecond += time.m_MilliSecond;
			return *this;
		}

		const Time& operator-= (const Time& time)
		{
			m_MilliSecond -= time.m_MilliSecond;
			return *this;
		}

	private:
		//1970��1��1��0ʱ�����ڵĺ�����
		UInt64	m_MilliSecond;
	};


	inline const Time operator+ (const Time& time1, const Time& time2)
	{
		return time1.m_MilliSecond + time2.m_MilliSecond;
	}

	inline const Time operator- (const Time& time1, const Time& time2)
	{
		return time1.m_MilliSecond - time2.m_MilliSecond;
	}
}

#endif