#include <iostream>

namespace Web
{
class WebBrowser
{
public:
	void clearCache()
	{
	}
	void clearHistory()
	{
	
	}
	void removeCookies()
	{
	
	}
};
void clearBuff(WebBrowser& wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}
}
