#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;
public:
    MediaFile(string path, double sz) : filePath(path), size(sz) {}
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolutionX, resolutionY;
public:
    VisualMedia(string path, double sz, int x, int y) : MediaFile(path, sz), resolutionX(x), resolutionY(y) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, double sz, int rate) : MediaFile(path, sz), sampleRate(rate) {}
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double sz, int x, int y) : MediaFile(path, sz), VisualMedia(path, sz, x, y) {}
    void play() override { cout << "Displaying image: " << filePath << endl; }
    void stop() override { cout << "Closing image: " << filePath << endl; }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double sz, int rate) : MediaFile(path, sz), AudioMedia(path, sz, rate) {}
    void play() override { cout << "Playing audio: " << filePath << endl; }
    void stop() override { cout << "Stopping audio: " << filePath << endl; }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double sz, int x, int y, int rate) 
        : MediaFile(path, sz), VisualMedia(path, sz, x, y), AudioMedia(path, sz, rate) {}
    void play() override { cout << "Playing video: " << filePath << " with resolution " << resolutionX << "x" << resolutionY << " and sample rate " << sampleRate << endl; }
    void stop() override { cout << "Stopping video: " << filePath << endl; }
};

int main() {
    vector<MediaFile*> library;
    library.push_back(new ImageFile("image.jpg", 2.5, 1920, 1080));
    library.push_back(new AudioFile("song.mp3", 5.0, 44100));
    library.push_back(new VideoFile("video.mp4", 50.0, 1920, 1080, 48000));
    
    for (auto file : library) file->play();
    for (auto file : library) file->stop();
    for (auto file : library) delete file;
}
