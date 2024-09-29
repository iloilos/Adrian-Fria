def encrypt(text):
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            shift = 5
            if char.islower():
                encrypted_text += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            else:
                encrypted_text += chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
        else:
            encrypted_text += char
    return encrypted_text

def decrypt(text):
    decrypted_text = ""
    for char in text:
        if char.isalpha():
            shift = 5
            if char.islower():
                decrypted_text += chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
            else:
                decrypted_text += chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
        else:
            decrypted_text += char
    return decrypted_text

def main():
    user_input = input("Enter a word or a sentence to encrypt: ")
    encrypted_text = encrypt(user_input)
    print("Encrypted text:", encrypted_text)

    user_input = input("Enter a word or a sentence to decrypt: ")
    decrypted_text = decrypt(user_input)
    print("Decrypted text:", decrypted_text)

if __name__ == "__main__":
    main()