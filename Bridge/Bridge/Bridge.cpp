#include "Bridge.h"

Webpage::~Webpage()
{
}

Webpage::Webpage(Theme * th):th(th)
{
	
}

Theme::Theme(string color):color(color)
{
}

Theme::~Theme()
{
}

Dark::Dark(string d):Theme(d)
{
}

string Dark::getColor()
{
	return color;
}

Light::Light(string light):Theme(light)
{
}

string Light::getColor()
{
	return color;
}



string Homes::getContent()
{
	return "Home page Theme: "+th->getColor();
}

About::About(Theme * th):Webpage(th)
{
}

string About::getContent()
{
	return "About content. Theme: "+th->getColor();
}

Career::Career(Theme * th):Webpage(th)
{
}

string Career::getContent()
{
	return "Career content. Theme: "+th->getColor();
}


