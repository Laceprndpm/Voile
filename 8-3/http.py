# import requests
# response=requests.get("http://books.toscrape.com/")
# with open('example.txt', 'w',encoding="UTF-8") as file:
#     file.write(response.text)
# print(response.status_code)
import requests
headers ={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:127.0) Gecko/20100101 Firefox/127.0"
}
html = requests.get(f"https://toho-vote.info/",headers=headers).text
with open('example.txt', 'w', encoding="utf-8") as file:
    file.write(html)
