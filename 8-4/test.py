from bs4 import BeautifulSoup
import requests
content=requests.get("https://books.toscrape.com/").text
soup=BeautifulSoup(content,"html.parser")
# all_prices=soup.findAll("p",attrs={"class":"price_color"})
all_titles=soup.findAll("h3")
with open('example.txt', 'w',encoding="utf-8") as file:
    file.write("")#初始化文本内容
# for price in all_prices:
    # with open('example.txt', 'a',encoding="utf-8") as file:
    #     file.write(price.string[2:])
with open('example.txt', 'a',encoding="utf-8") as file:
    for title in all_titles:
        link=title.find("a")
        file.write(link.text+"\n")