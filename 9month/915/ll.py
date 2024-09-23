import requests

# 登录信息
username = "1601240061"
password = "c1105e3910@1977"

# 登录 URL
login_url = "https://cas.hytc.edu.cn/lyuapServer/login"  # 替换为实际的登录 URL

# 请求头
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:130.0) Gecko/20100101 Firefox/130.0'
}

# 登录函数
def login():
    # 登录数据
    login_data = {
        "username": username,
        "password": password
    }
    
    try:
        # 发起 POST 请求进行登录
        response = requests.post(login_url, data=login_data, headers=headers)
        
        # 检查响应状态码
        response.raise_for_status()
        
        # 检查是否登录成功，可以根据实际情况调整
        if "登录成功" in response.text or response.url != login_url:
            print("登录成功")
            return response.cookies
        else:
            print("登录失败")
            return None
    except requests.RequestException as e:
        print(f"请求发生错误: {e}")
        return None

# 执行登录
cookies = login()
if cookies:
    print("获取到的 cookies:", cookies)
else:
    print("未能获取到 cookies")