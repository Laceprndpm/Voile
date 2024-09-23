import requests
cookies={'insert_cookie':'96816998','JSESSIONID':'24F39281051DBFF61EB13E5C242C7A02'}
c = requests.get("https://portal.hytc.edu.cn/",cookies=cookies,verify=False)
print(c.text)