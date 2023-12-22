import requests


def get(url):
    resp = requests.get(url)
    if resp.status_code == 200:
        return resp.json()


def downloadUrl(url):
    resp = requests.get(url, True)
    headers = resp.headers
    file_format= headers['content-type'].split('/')[1]
    filename = 'imageoftheday'+"."+file_format
    with open(filename, 'wb') as localFile:
       localFile.write(resp.content)


def main():
    base_url="http://www.bing.com"
    url = "http://www.bing.com/HPImageArchive.aspx?format=js&idx=0&n=1"
    response_json = get(url)

    image = response_json['images']
    image_url = image[0]['url']

    image = base_url + image_url
    downloadUrl(image)


if __name__ == "__main__":
    main()
