#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

char icon_check(string);
void draw_weather(sf::RenderWindow*,char,int,string,string,string,int,string,string);

int main()
{
	string main,desc,temp_str,icon,aqiusStr,city;
	int temp,time,aqius=0;
	char iconType;
	
	ifstream input;
	input.open("weather_data.txt");
	getline(input,main);
	getline(input,desc);
	getline(input,temp_str);
	getline(input,icon);
	input>>time;
	input>>aqiusStr;
	input>>city;
	input.close();
	
	temp=stoi(temp_str);	//string to integer
	cout<<main<<endl;
	cout<<desc<<endl;
	cout<<temp<<endl;
	cout<<icon<<endl;
	cout<<time<<endl;
	cout<<aqiusStr<<endl;
	aqius=stoi(aqiusStr);

	
	iconType=icon_check(icon);
	//***************SFML*******************
	sf::RenderWindow window(sf::VideoMode(450,600),"Weather");
	window.setVerticalSyncEnabled(true);
	
	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}
			draw_weather(&window,iconType,time,main,desc,temp_str,aqius,aqiusStr,city);
		}
	}
	return(0);
}

char icon_check(string icon)
{
	if(icon=="01d" || icon=="01n")
	{
		return('1');
	}
	else if (icon=="02d" || icon=="02n")
	{
		return('2');
	}
	else if (icon=="03d" || icon=="03n")
	{
		return('3');
	}
	else if (icon=="04d" || icon=="04n")
	{
		return('4');
	}
	else if (icon=="09d" || icon=="09n")
	{
		return('5');
	}
	else if (icon=="10d" || icon=="10n")
	{
		return('6');
	}
	else if (icon=="11d" || icon=="11n")
	{
		return('7');
	}
	else if (icon=="13d" || icon=="13n")
	{
		return('8');
	}
	else if (icon=="50d" || icon=="50n")
	{
		return('9');
	}
	else if (icon=="Not Found")
	{
		return('0');
	}
}

void draw_weather(sf::RenderWindow *window,char iconType,int time,string main,string desc,string temp_str,int aqius,string aqiusStr,string city)
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text text1;
	sf::Text text2;
	sf::Text text_aqius;
	sf::Text text_condition;
	sf::Text text_city;
	sf::Font font;
	font.loadFromFile("FiraSans-Book.otf");
	sf::String string1;
	sf::String string2;
	sf::String string3;
	sf::String string4;
	sf::String string5;
	text1.setFont(font);
	text1.setFillColor(sf::Color::Yellow);
	text2.setFont(font);
	text_aqius.setFont(font);
	text_condition.setFont(font);
	text_city.setFont(font);
	string1="-> "+main+"\n-> "+desc+"\n-> "+temp_str+"*C\n";
	string3="-> Aqius: "+aqiusStr;
	cout<<aqius<<endl;
	text_aqius.setString(string3);
	text_city.setString(city);
	text_city.setPosition(140,260);
	text_city.setFillColor(sf::Color::Magenta);
	if(aqius<=50)
	{
		string4="Pollutition level: Good";
		text_aqius.setFillColor(sf::Color::Green);
		text_condition.setFillColor(sf::Color::Green);
	}
	else if(aqius>50 && aqius<=100)
	{
		string4="Pollutition level: Moderate";
		text_aqius.setFillColor(sf::Color::Yellow);
		text_condition.setFillColor(sf::Color::Yellow);
	}
	else if(aqius>100 && aqius<=150)
	{
		string4="Pollutition level: Unhealthy for Sensitive Groups";
		text_aqius.setFillColor(sf::Color(153,0,76,0));
		text_condition.setFillColor(sf::Color(153,0,76,0));
	}
	else if(aqius>150 && aqius<=200)
	{
		string4="Pollutition level: Unhealthy";
		text_aqius.setFillColor(sf::Color::Red);
		text_condition.setFillColor(sf::Color::Red);
	}
	else if(aqius>200 && aqius<=300)
	{
		string4="Pollutition level: Very Unhealthy";
		text_aqius.setFillColor(sf::Color::Magenta);
		text_condition.setFillColor(sf::Color::Magenta);
	}
	else if(aqius>300 && aqius<=500)
	{
		string4="Pollutition level: Hazardous";
		text_aqius.setFillColor(sf::Color::Black);
		text_condition.setFillColor(sf::Color::Black);
	}
	text_aqius.setString(string3);
	text_condition.setString(string4);
	text_aqius.setPosition(20,460);
	text_condition.setPosition(20,490);
	text1.setString(string1);
	text1.setPosition(20,340);
	if(time>5 && time<19){text2.setString("Good Day");}
	else{text2.setString("Good Night");}
	text2.setPosition(140,300);
	text2.setFillColor(sf::Color::Yellow);
	sprite.setPosition(32,0);
	//iconType='5'; //for testing
	switch (iconType)
	{
		case '1':
			if(time>5 && time<19){texture.loadFromFile("sun.png");}
			else{texture.loadFromFile("moon.png");}
			break;
		case '2':
			if(time>5 && time<19){texture.loadFromFile("sun_cloudy.png");}
			else{texture.loadFromFile("moon_cloudy.png");}
			break;
		case '3':
			texture.loadFromFile("clouds.png");
			break;
		case '4':
			texture.loadFromFile("clouds.png");
			break;
		case '5':
			if(time>5 && time<19){texture.loadFromFile("sun_rain.png");}
			else{texture.loadFromFile("moon_rain.png");}
			break;
		case '6':
			texture.loadFromFile("rain.png");
			break;
		case '7':
			texture.loadFromFile("thunderstorm.png");
			break;
		case '8':
			if(time>5 && time<19){texture.loadFromFile("sun_snow.png");}
			else{texture.loadFromFile("moon_snow.png");}
			break;
		case '9':
			sprite.setPosition(0,0);
			texture.loadFromFile("mist.png");
			break;
		case '0':
			sprite.setPosition(100,0);
			texture.loadFromFile("notfound.png");
			break;

	}
	if(time>5 && time<19){window->clear(sf::Color(0, 204, 255));}
	else{window->clear(sf::Color(0, 51, 102));}
	sprite.setTexture(texture);
	window->draw(text_city);
	window->draw(sprite);
	window->draw(text1);
	window->draw(text2);
	window->draw(text_aqius);
	window->draw(text_condition);
	window->display();
}
