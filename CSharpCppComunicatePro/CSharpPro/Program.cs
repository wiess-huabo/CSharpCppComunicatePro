using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpPro
{
	class Program
	{

		static void Main(string[] args)
		{
			var m_authSdk = new AuthCSharp();
			m_authSdk.Login(1111, "11111", 111);
		}
	}
}
