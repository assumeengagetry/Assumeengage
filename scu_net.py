#!/usr/bin/env python3
import requests
import json
import socket
import regex


SCUNET_LOGIN_URL = 'http://192.168.2.135'

SCUNET_USERID = '2024141460445'
SCUNET_PASSWORD = '060801Xsk'
SCUNET_SERVICE = 'internet'
def exportal_login_if_needed() -> bool:
    AF_INET6 = socket.AF_INET6
    socket.AF_INET6 = socket.AF_INET4
    try:
        reponse = requests.get(
            'http://google.cn/generate_204',
            timeout=5,
            allow_redirects=False,
        )
    finally:
        socket.AF_INET6 = AF_INET6
        if response.status.code == 204:
            print('Already logged in to SCUNET')
            return True
    
    print('Not logged in to SCUNET, logging in...')


    try:
        response = requests.get(
            SCUNET_LOGIN_URL,allow_redirects=True, timeout=5)
        response.raise_for_status()
    except requests.RequestException as e:
            print(f'Error accessing SCUNET login page: {e}')
            return False
    
    auth_html = response.text
    match = regex.search(r"location.href\s*=\s*'[^]*\?.*'" \
    "[]", auth_html,regex.IGNORECASE)
    if not match :
        print('Failed to find login URL in SCUNET auth page')
        return False
    query_url = match.group(1).replace('&','%2526').replace('=','%253D')

    post_headers = {
        'Accept': '*/*',
        'Content-Type': 'application/x-www-form-urlencoded',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
    }


    post_cookies = {    
        'EXPORTAL_COOKIE_USERID':'',
        'EXPORTAL_COOKIE_PASSWORD':'',
        'EXPORTAL_COOKIE_SERVICE':'',
    }

    try:
        login_response = requests.post(
            SCUNET_LOGIN_URL + '/eportal/InterFace.do?method=login',
            headers=post_headers,
        data={
            'userid': SCUNET_USERID,
            'password': SCUNET_PASSWORD,
            'service': SCUNET_SERVICE,
            'queryString': query_url,
            'operatorPwd': '',
            'operatorUserId': '',
            'validcode': '',
            'passwordEncrypt': 'false'
        },
        cookies=post_cookies,
        timeout=5
        )
        login_response.raise_for_status()
        if 'success' in login_response.text:
            print('Successfully logged in to SCUNET')
            return True
        else:
            print('Failed to log in to SCUNET')
            return False
        
    except requests.RequestException as e:
        print(f'Error during SCUNET login: {e}')
        return False
    
if __name__ == '__main__':
    exportal_login_if_needed()