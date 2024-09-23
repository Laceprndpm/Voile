# from booking.booking import booking
# with booking(teardown=False) as bot:
#     bot.land_frist_page()
#     print('test')
#     bot.change_currency()
# input()

from booking.booking import booking
with booking(teardown=False) as bot:
    bot.land_frist_page()
    bot.login()
    bot.change_page()
    temp=bot.pick()
    bot.handle_courses(temp)
input()
# import requests
# def parse_cookie_string(cookie_string):
#     # 使用分号将字符串分割成键值对
#     cookies = {}
#     for item in cookie_string.split(';'):
#         key, value = item.strip().split('=', 1)
#         cookies[key] = value
#     return cookies

# cookie_string = "show_vpn=0; show_fast=0; heartbeat=1; show_faq=0; wengine_vpn_ticketwvpn_ahu_edu_cn=a1ca09af9de2390d; refresh=1; route=e8c416b0b801233f371d9cc5c6ae6493"
# cookies = parse_cookie_string(cookie_string)
# headers = {'User-Agent':
# 	'Mozilla/5.0 (Windows NT 5.1; rv:52.0) Gecko/20100101 Firefox/52.0'}
# web=requests.get(url='https://wvpn.ahu.edu.cn/',headers=headers,cookies=cookies)
# print(web.status_code)
# with open('example.html', 'w', encoding="utf-8") as file:
#     file.write(web.text)