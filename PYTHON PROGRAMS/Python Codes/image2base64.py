import base64
from PIL import Image

def image_to_base64(img_path):
    with open(img_path, 'rb') as image_file:
        encoded_string = base64.b64encode(image_file.read()).decode('utf-8')
    return encoded_string

def save_to_file(data, output_path):
    with open(output_path, 'w') as output_file:
        output_file.write(data)

def main():
    img_path = input("Enter the path to the image file: ")
    output_path = input("Enter the path of the output file: ")

    base64_data = image_to_base64(img_path)
    save_to_file(base64_data, output_path)

    print(f"The image file has been converted and saved in {output_path}")

if __name__ == "__main__":
    main()