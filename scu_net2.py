#!/usr/bin/env python3

import requests
import regex
import json
import socket

SCUNET_LOGIN_URL = 'http://192.168.2.135'

## Your student ID and password
SCUNET_USERID = '2024141460445'
SCUNET_PASSWORD = '060801Xsk'

## Choose a service, where:
##   'internet': campus network / edu network
##   '%25E7%25A7%25BB%25E5%258A%25A8%25E5%2587%25BA%25E5%258F%25A3': China Mobile
SCUNET_SERVICE='internet'

def eportal_login_if_needed() -> bool:
    # requests.get() will try IPv6 first (if you are assigned with an IPv6 address),
    # which will freeze the whole program. We must force it to use IPv4 instead.
    # I know this is fucking ugly, but it is the easist way to get it work.
    AF_INET6 = socket.AF_INET6
    socket.AF_INET6 = socket.AF_INET
    response = requests.get(
        'http://www.google.cn/generate_204',
        allow_redirects=False
    )
    socket.AF_INET6 = AF_INET6

    if response.status_code == 204:
        print('network check: Internet connectivity OK')
        return True

    print('network check: no Internet, try to login')

    response = requests.get(SCUNET_LOGIN_URL, allow_redirects=True)
    if response.status_code != 200:
        print('network login: failed to request login page')
        return False

    # The response looks like: <script>top.self.location.href='http://...?QUERY_STRING'</script>
    # We need to get the QUERY_STRING
    auth_page_html = response.content.decode()
    query_string = regex.match('<script>.+=\'.*\\?(.*)\'</script>', auth_page_html).group(1)
    query_string = query_string.replace('&', '%2526').replace('=', '%253D')

    # Maybe query_string identifies a auth device like a wireless AC/AP.

    post_headers = {
        'Accept': '*/*',
        'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8',
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36',
    }

    post_cookies = {
        'EPORTAL_COOKIE_USERNAME': '',
        'EPORTAL_COOKIE_PASSWORD': '',
        'EPORTAL_COOKIE_SERVER': '',
        'EPORTAL_COOKIE_SERVER_NAM': '',
        'EPORTAL_AUTO_LAND': '',
        'EPORTAL_USER_GROUP': '',
        'EPORTAL_COOKIE_OPERATORPWD': ''
    }

    login_resp = requests.post(
        SCUNET_LOGIN_URL + '/eportal/InterFace.do?method=login',
        headers=post_headers,
        data=(  f'userId={SCUNET_USERID}&'
              + f'password={SCUNET_PASSWORD}&'
              + f'service={SCUNET_SERVICE}&'
              + f'queryString={query_string}&'
              + f'operatorPwd=&operatorUserId=&validcode=&passwordEncrypt=false'
             ).encode(),
        cookies=post_cookies
    )

    if login_resp.status_code != 200:
        print('network login: failed to submit POST request')
        return False

    result = json.loads(login_resp.content.decode())
    if result['result'] == 'success':
        print('network login: success')
        return True

    return False

if __name__ == '__main__':
    eportal_login_if_needed()