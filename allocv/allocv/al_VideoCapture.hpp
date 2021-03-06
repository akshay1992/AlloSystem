#ifndef INCLUDE_AL_VIDEO_CAPTURE_HPP
#define INCLUDE_AL_VIDEO_CAPTURE_HPP

/*	AlloSystem --
	Multimedia / virtual environment application class library

	Copyright (C) 2009. AlloSphere Research Group, Media Arts & Technology, UCSB.
	Copyright (C) 2012. The Regents of the University of California.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

		Redistributions of source code must retain the above copyright notice,
		this list of conditions and the following disclaimer.

		Redistributions in binary form must reproduce the above copyright
		notice, this list of conditions and the following disclaimer in the
		documentation and/or other materials provided with the distribution.

		Neither the name of the University of California nor the names of its
		contributors may be used to endorse or promote products derived from
		this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.


	File description:
	VideoCapture using OpenCV

	File author(s):
	Lance Putnam, 2014, putnam.lance@gmail.com
*/

#include "allocore/system/al_PeriodicThread.hpp"
#include "allocv/al_OpenCV.hpp"

namespace al{

/// Video capture from files or cameras

/// This is basically a direct wrapper around cv::VideoCapture.
/// Note that frame numbering follows 0-based indexing. That is, for a video
/// file having N frames, the frame numbers are in [0, N-1].
class VideoCapture{
public:

	/// Underlying OpenCV VideoCapture object
	mutable cv::VideoCapture cvVideoCapture;

	/// The last retrieved video frame
	cv::Mat cvFrame;


	VideoCapture();

	~VideoCapture();

	/// Open a video file

	/// @param[in] filename	Path to video file (e.g., video.avi) or
	///						image sequence (e.g., img_%02d.jpg, which will read
	///						samples img_00.jpg, img_01.jpg, img_02.jpg, ...).
	/// \returns true on success.
	bool open(const std::string& filename);

	/// Open a video input device (i.e., camera)

	/// @param[in] device	Enumeration number of video device
	/// \returns true on success.
    bool open(int device);


	/// Closes video
	void release();


	/// Grabs the next frame from video file or capturing device

	/// \returns true on success.
	///
	bool grab();

	/// Decodes and returns the grabbed video frame

	/// @param[in] dst			the array to copy the frame into
	/// @param[in] chan			the video channel to retrieve
	/// @param[in] copyPolicy	Policy on copying data:
	///							 1 = copy data with same row order (default),
	///							-1 = copy data with rows flipped.
	///
	/// \returns false if no frame has been grabbed (camera has been
	/// disconnected, or there are no more frames in video file).
	bool retrieve(Array& dst, int chan=0, int copyPolicy=1);

	/// Decodes and returns the grabbed video frame

	/// @param[in] dst			the array to copy the frame into
	/// @param[in] chan			the video channel to retrieve
	///
	/// \returns false if no frame has been grabbed (camera has been
	/// disconnected, or there are no more frames in video file).
	bool retrieve(cv::Mat& dst, int chan=0);

	/// Decodes the grabbed video frame into cv::Mat member

	/// @param[in] chan			the video channel to retrieve
	///
	/// \returns false if no frame has been grabbed (camera has been
	/// disconnected, or there are no more frames in video file).
	bool retrieve(int chan=0);

	/// Decodes and returns the grabbed video frame flipped vertically

	/// @param[in] dst			the array to copy the frame into
	/// @param[in] chan			the video channel to retrieve
	///
	/// \returns false if no frame has been grabbed (camera has been
	/// disconnected, or there are no more frames in video file).
	bool retrieveFlip(Array& dst, int chan=0);

	/// Grabs, decodes and returns the next video frame

	/// @param[in] dst			the array to copy the frame into
	/// @param[in] copyPolicy	Policy on copying data:
	///							 1 = copy data with same row order (default),
	///							-1 = copy data with rows flipped.
	///
	/// \returns true on success.
	bool read(Array& dst, int copyPolicy=1);


	/// Set an OpenCV video property
	bool set(int cvCapProp, double val);

	/// Set width in pixels
	VideoCapture& width(double pixels);

	/// Set height in pixels
	VideoCapture& height(double pixels);

	/// Set width and height in pixels
	VideoCapture& resize(double width, double height);

	/// Set position in msec (files only)
	VideoCapture& posMsec(double msec);

	/// Set position in frames (files only)
	VideoCapture& posFrames(double frame);

	/// Set position as fraction, in [0,1], of total duration (files only)
	VideoCapture& posFrac(double frac);

	/// Set frame/capture rate (typically for cameras only)
	VideoCapture& fps(double val);

	/// Set playback rate multiplier, in (0, inf) (files only)
	VideoCapture& rate(double fpsMul);


	/// Get an OpenCV video property
	double get(int cvCapProp) const;

	/// Returns whether video is opened
	bool isOpened() const;

	/// Get frames/second
	double fps() const;

	/// Get total number of frames (files only)
	double numFrames() const;

	/// Get playback rate (files only)
	double rate() const;

	/// Get width, in pixels
	double width() const;

	/// Get height, in pixels
	double height() const;

	/// Get aspect ratio (width/height)
	double aspect() const;

	/// Get whether frames are RGB (versus BGR)
	bool rgb() const;

	/// Get four-character codec code
	int fourcc() const;

	/// Get four-character codec code as string
	std::string fourccString() const;

	/// Get position in msec (files only)
	double posMsec() const;

	/// Get position as fraction, in [0,1], of total duration (files only)
	double posFrac() const;

	/// Get position in frames
	double posFrames() const;

	/// Loop current position between endpoints (files only)

	/// @param[in] minFrame		The minimum endpoint
	/// @param[in] maxFrame		The maximum endpoint;
	///							if < 0, then use numFrames + maxFrame + 1
	/// \returns true if the video looped, false otherwise.
	///
	/// Note: OpenCV can be very fussy about reading frames near the end of the
	/// file. Therefore, small negative values for maxFrame will not always work
	/// as expected. A more reliable strategy is to use the return value of
	/// retrieve* or read calls to determine whether to loop.
	bool loop(double minFrame=0, double maxFrame=-1);

	/// Get whether "capture" is a file
	bool isFile() const;

	/// Print information about video
	void print(FILE * fp = stdout);

private:
	friend class VideoCaptureHandler;
	double mFPS;
	double mRate;
	double mBadFrame;
	bool mIsFile;
	bool mValid;
};


/// Handler for one or more video capture threads
class VideoCaptureHandler{
public:

	struct VideoThreadFunction : public al::ThreadFunction{
		VideoThreadFunction();
		~VideoThreadFunction();
		void operator()();
		al::VideoCapture * videoCapture;
		VideoCaptureHandler * handler;
		int streamIdx;
	};

	struct WorkThread{
		~WorkThread();
		PeriodicThread thread;
		VideoThreadFunction func;
		void start();
		void stop();
	};


	typedef std::vector<WorkThread> WorkThreads;


	/// @param[in] numStreams	number of video streams to handle
	VideoCaptureHandler(int numStreams = 1);

	virtual ~VideoCaptureHandler();


	/// Called whenever new video frame(s) are ready
	virtual void onVideo(VideoCapture& vid, int streamIdx) = 0;

	/// Called just before a grab is attempted

	/// Any state handling of VideoCaptures should happen here.
	///
	virtual void onPregrab(VideoCapture& vid, int streamIdx){}


	/// Set maximum number of handled video capture streams
	VideoCaptureHandler& numVideoStreams(int num);

	/// Get maximum number of handled video capture streams
	int numVideoStreams() const;

	/// Attach a video capture object

	/// @param[in] vid			video capture to attach
	/// @param[in] streamIdx	stream index (must be <= numStreams())
	VideoCaptureHandler& attach(VideoCapture& vid, int streamIdx=0);

	/// Start the video thread(s)
	void startVideo();

	/// Stop the video thread(s)
	void stopVideo();

private:
	WorkThreads mWorkThreads;
};

} // al::

#endif
