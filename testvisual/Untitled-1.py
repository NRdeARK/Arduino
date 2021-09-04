t=input("")
text=str(t)
TEXT=text.upper
for i in text:
    if (TEXT[i] in "ABCDEFGHIJKLNMOPQRSTUVWXYZ"):
        print(text[i])
