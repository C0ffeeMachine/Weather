import requests
import datetime
import time
userinput=int(input("Enter 1 for auto-detecting your location\nEnter 2 for custom input: "))

if(userinput==1):
    response=requests.get("http://api.airvisual.com/v2/nearest_city?key=AucAj69TfcZdajGo9")
    data=response.json()

    api_address='http://api.openweathermap.org/data/2.5/weather?appid=0c42f7f6b53b244c78a418f4f181282a&q='
    city=str(data["data"]["city"])
    state=str(data["data"]["state"])
    country=str(data["data"]["country"])
else:
    api_address='http://api.openweathermap.org/data/2.5/weather?appid=0c42f7f6b53b244c78a418f4f181282a&q='
    city=str(input("Enter the City name: "))
    state=str(input("Enter the State name: "))
    country=str(input("Enter the Country name: "))

pollution_address="http://api.airvisual.com/v2/city?city="
pollution_url=pollution_address+city+"&state="+state+"&country="+country+"&key=wfWC5aX8bDn9yo6so"
json_data_pollution=requests.get(pollution_url).json();

url=api_address+city+"&units=metric";
json_data=requests.get(url).json();
try:
    formatted_data_desc=json_data['weather'][0]['description']
    formatted_data_main=json_data['weather'][0]['main']
    formatted_data_temp=json_data['main']['temp']
    formatted_data_icon=json_data['weather'][0]['icon']
    formatted_data_pollution_aqius=json_data_pollution['data']['current']['pollution']['aqius']
except:
    formatted_data_desc="Not Found";
    formatted_data_main="Not Found";
    formatted_data_temp="0";
    formatted_data_icon="Not Found";
    formatted_data_pollution_aqius="0";
    city="Not Found";

print(formatted_data_main)
print(formatted_data_desc)
print(formatted_data_temp)
print(formatted_data_icon)
print(formatted_data_pollution_aqius)
print(json_data);
print(json_data_pollution)
print(datetime.datetime.now().time())
print(time.strftime("%H %M %S"))

fobject =open("weather_data.txt", "w");
fobject.write(formatted_data_main);
fobject.write("\n");
fobject.write(formatted_data_desc);
fobject.write("\n");
fobject.write(str(formatted_data_temp));    #typecasted to string
fobject.write("\n");
fobject.write(formatted_data_icon);
fobject.write("\n");
if(formatted_data_icon.find("n")!=-1):
    fobject.write("19")
else:
    fobject.write(time.strftime("10"));
fobject.write("\n");
fobject.write(str(formatted_data_pollution_aqius));
fobject.write("\n");
fobject.write(city);
fobject.write("\n");
fobject.close();
