import requests

# 定义要爬取的URL
url = 'https://uzkk.github.io/favorite/'

# 发送HTTP请求
response = requests.get(url)

# 检查请求是否成功
if response.status_code == 200:
    # 获取网页内容
    html_content = response.text
    
    # 保存内容到html.txt文件
    with open('html.txt', 'w', encoding='utf-8') as file:
        file.write(html_content)
    
    print('网页内容已成功保存到html.txt')
else:
    print(f'请求失败，状态码：{response.status_code}')