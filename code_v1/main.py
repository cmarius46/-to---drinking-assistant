

# import sounddevice as sd
# import numpy as np
# import speech_recognition as sr
#
# fs = 44100  # Sample rate
# seconds = 3  # Duration of recording
#
# myRecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2)
# sd.wait()  # Wait until recording is finished
# sd.play(myRecording, fs)
# sd.wait()
#
# r = sr.Recognizer()
#
# text = r.recognize_google(myRecording)
#
# print(text)

import speech_recognition as sr

# Initialize recognizer class (for recognizing the speech)

r = sr.Recognizer()

# Reading Microphone as source
# listening the speech and store in audio_text variable

with sr.Microphone() as source:
    print("Talk")
    audio_text = r.listen(source)
    print("Time over, thanks")
    # recoginize_() method will throw a request error if the API is unreachable, hence using exception handling

    try:
        # using google speech recognition
        print("Text: " + r.recognize_google(audio_text))
    except:
        print("Sorry, I did not get that")
#         https://towardsdatascience.com/easy-speech-to-text-with-python-3df0d973b426

