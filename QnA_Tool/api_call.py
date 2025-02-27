import openai
import sys
if __name__ == '__main__':
    
    # python3 <filename> API_KEY paragraph_0.txt paragraph_1.txt paragraph_2.txt query.txt
    if len(sys.argv) < 5:
        print("Usage: python3 api_call.py API_KEY paragraph_0.txt paragraph_1.txt paragraph_2.txt paragraph_3.txt query.txt")
        sys.exit(1)
    # Read the API key from the command line
    openai.api_key = sys.argv[1]
    # Read the paragraphs from the files
    paragraphs = []
  #  flag=TRUE
    for i in range(2, len(sys.argv)):
        with open(sys.argv[i], 'r') as f:
            paragraphs.append(f.read())  
    #   for i in range(paragraphs.len()):
    #     paragraph[0]
   # max_length=4000
    paragraphs = '\n'.join(paragraphs)
   # if(len(paragraphs)>max_length):
    #    paragraphs=paragraphs[:max_length]
    query = {
        "role": "user", "content": paragraphs
    }
    chat = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[query]
    )
    reply = chat.choices[0].message.content
    #print("response below")
    print(reply)

