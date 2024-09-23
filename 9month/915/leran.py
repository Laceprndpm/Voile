# from selenium import webdriver
# from selenium.webdriver.common.by import By
# from selenium.webdriver.support.ui import WebDriverWait
# from selenium.webdriver.support import expected_conditions as EC

# driver = webdriver.Firefox()
# driver.get("https://www.bilibili.com/")
# button = driver.find_element(By.CLASS_NAME, 'roll-btn')
# while (EC.text_to_be_present_in_element(By.CLASS_NAME,))
# button.click()
# driver.implicitly_wait(30)
# input("Press Enter to close the browser after download is completed...")
# WebDriverWait(driver,30).until(EC.text_to_be_present_in_element(By.CLASS_NAME,))
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException
import time
import requests
# 初始化 WebDriver
driver = webdriver.Firefox()

# 打开目标网页
driver.get("https://cas.hytc.edu.cn/lyuapServer/login")
driver.implicitly_wait(5)
username = driver.find_element(By.ID,'username')
passwd = driver.find_element(By.ID,'password')
button = driver.find_element(By.CLASS_NAME,'btn-submit')
username.send_keys(1601240061)
passwd.send_keys('c1105e3910@1977')
button.click()
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:130.0) Gecko/20100101 Firefox/130.0'
}
relative_src = "/documents/10194/12305/201708250904542133896190313721102.png"
# 使用绝对路径查找图像
image_xpath = f"//img[@src='{relative_src}']"
image = driver.find_element(By.XPATH, image_xpath)
driver.execute_script("arguments[0].scrollIntoView(true);", image)
time.sleep(2)
image.click()
time.sleep(2)
input()
# driver.implicitly_wait(5)
# # 找到刷新按钮
# refresh_button = driver.find_element(By.CLASS_NAME, 'roll-btn')

# while True:
#     try:
#         # 等待直到目标文本出现
#         WebDriverWait(driver, 2).until(
#             EC.text_to_be_present_in_element(
#                 (By.XPATH, "///html/body/div[2]/div[2]/main/div[2]/div/div[1]/div[2]/div/div[2]/div/div/h3"),
#                 "我"
#             )
#         )
#         print("目标文本 '我' 已出现。")
#         break  # 退出循环
#     except TimeoutException:
#         # 捕获 TimeoutException 并点击刷新按钮
#         print("超时: 目标文本 '我' 未出现，点击刷新按钮。")
#         refresh_button.click()
# input('hehe')
# # 确保浏览器在结束时关闭
# driver.quit()
