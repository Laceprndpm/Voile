import requests
headers = {'User-Agent':
	'Mozilla/5.0 (Windows NT 5.1; rv:52.0) Gecko/20100101 Firefox/52.0'}
html=requests.get('https://www.bilibili.com',headers=headers)
with open('example.html', 'w', encoding="utf-8") as file:
    file.write(html.text)