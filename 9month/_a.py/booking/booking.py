from types import TracebackType
from typing import Type
from selenium import webdriver
from selenium.webdriver.common.by import By
import booking.constants as const
import time
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

class booking(webdriver.Firefox):
    def __init__(self,teardown=True):
        super(booking,self).__init__()
        self.teardown = teardown
        self.implicitly_wait(60)
        self.maximize_window()
        self.wait = WebDriverWait(self,10)

    def __exit__(self, exc_type: type[BaseException] | None, exc: BaseException | None, traceback: TracebackType | None):
        if self.teardown:
            self.quit()

    def land_frist_page(self):
        self.get(const.domain)

    def change_currency(self):
        button = self.find_element(By.CSS_SELECTOR,'button[data-testid="header-currency-picker-trigger"]')
        button.click()
        li_elements = self.wait.until(EC.presence_of_all_elements_located((By.CSS_SELECTOR, 'li.b817090550.c44c37515e')))
        # li_elements = self.find_elements(By.CSS_SELECTOR, 'li.b817090550.c44c37515e')
        # 1. 遍历 li 元素
        for li in li_elements:
            try:
                # 2. li 元素内部查找 button 元素
                button = li.find_element(By.CSS_SELECTOR, 'button[data-testid="selection-item"]')
                
                # 3. 在button内部查找 div 元素
                currency_div = button.find_element(By.CSS_SELECTOR, 'div.CurrencyPicker_currency')
                
                # 4. 获取 div 的文本内容并检查是否是 USD
                if currency_div.text == "USD":
                    print("BINGO!")
                    currency_div.click()
                    break
                else:
                    print("Element found, but it's not USD:", currency_div.text)
            
            except Exception as e:
                # 如果找不到 button 或 div 或其他错误，打印错误信息
                print("Error occurred:", str(e))

