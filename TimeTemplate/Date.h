#ifndef _DATE_H_
#define _DATE_H_

#include "Time.h"
#include <ctime>

namespace Avalon
{
	/**
	*@brief �����࣬�����˻�ȡ�ꡢ�¡��յȽӿ�
	*/
	class Date
	{
	public:
		Date();
		explicit Date(const Time& time);
		~Date(){}

		Time ToTime() const;

		/**
		*@brief ���û�ȡ���
		*/
		Int32 Year() const{ return m_Tm.tm_year + 1900; }
		void Year(Int32 year){ m_Tm.tm_year = year - 1900; }

		/**
		*@brief ���û�ȡ�·�
		*/
		Int32 Month() const{ return m_Tm.tm_mon + 1; }
		void Month(Int32 month){ m_Tm.tm_mon = month - 1; }

		/**
		*@brief ���û�ȡ����
		*/
		Int32 Day() const{ return m_Tm.tm_mday; }
		void Day(Int32 day){ m_Tm.tm_mday = day; }

		/**
		*@brief ���û�ȡʱ
		*/
		Int32 Hour() const{ return m_Tm.tm_hour; }
		void Hour(Int32 hour){ m_Tm.tm_hour = hour; }

		/**
		*@brief ���û�ȡ��
		*/
		Int32 Min() const{ return m_Tm.tm_min; }
		void Min(Int32 min){ m_Tm.tm_min = min; }

		/**
		*@brief ���û�ȡ��
		*/
		Int32 Sec() const{ return m_Tm.tm_sec; }
		void Sec(Int32 sec){ m_Tm.tm_sec = sec; }

		/**
		*@brief ���û�ȡ����
		*/
		Int32 MSec() const{ return m_Msec; }
		void MSec(Int32 msec){ m_Msec = msec; }

		/**
		*@brief ���û�ȡ����
		*/
		Int32 WDay() const { return m_Tm.tm_wday == 0 ? 7 : m_Tm.tm_wday; }

		/**
		*@brief ��ȡ���µ�����
		*/
		Int32 GetDaysInMonth()
		{
			Int32 d;
			Int32 day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			if (2 == Month())
			{
				d = (0 == Year() % 4) && (0 != Year() % 100) || ((0 == Year() % 400) ? 29 : 28);
			}
			else
			{
				d = day[Month() - 1];
			}
			return d;
		}

	private:
		struct tm	m_Tm;
		//����
		Int32		m_Msec;
	};
}

#endif
