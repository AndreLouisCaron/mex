/*!
 * @file MJPEGToMStandardFormat.cpp
 * @author Typhaine Giraud (typhaine.giraud@usherbrooke.ca)
 * @author Andre Caron (andre.louis.caron@usherbrooke.ca)
 * @Matlab extension for converting MJPEG files into MStandard Format
 */

#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <iostream>
#include <cmath>
#include <mex.hpp>

namespace {
    
    void error ( const std::string& expected, const std::string& encountered )
    {
        if ( encountered != "" ) {
            std::ostringstream message;
            message
                << "Out of sync: expecting '" << expected
                << "', but encountered '" << encountered << "'.";
            mex::warning(message.str());
        }
    }

    std::size_t header ( std::istream& in )
    {
            // Parses header.
        std::string line;
        if (!std::getline(in,line) || (line != "--myboundary\r"))
        {
            error("--myboundary", line);
            return (0);
        }
        if (!std::getline(in,line) || (line != "Content-Type: image/jpeg\r")) {
            error("Content-Type: image/jpeg", line);
            return (0);
        }
        if (!std::getline(in,line,':') || (line != "Content-Length")) {
            error("Content-Length", line);
            return (0);
        }
        std::size_t length = 0;
        if (!(in >> length) && (length > 0)) {
            throw (std::exception("Invalid content length!"));
        }
        in.ignore(4);
        return (length);
    }

    std::string fileName ( std::size_t i, std::size_t granularity, std::size_t zeros, std::string base )
    {
        std::ostringstream name;
        const std::size_t n = std::ceil(std::log(double(granularity))/std::log(double(10)));
        name << base << std::setw(zeros) << std::setfill('0') << i/granularity*granularity << '/'
             << std::setw(n) << std::setfill('0') << i%granularity << ".jpg";
        return (name.str());
    }

    std::string folderName ( std::size_t i, std::size_t granularity, std::size_t zeros, std::string base )
    {
        std::ostringstream name;
        name << base << std::setw(zeros) << std::setfill('0') << i/granularity*granularity << '/';
        return (name.str());
    }
    
    const unsigned char Signature[] = {
        0xff, 0xd8, 0xff, 0xe0, 0x00, 0x10, 'J', 'F', 'I', 'F'
    };

    std::size_t MJPEGToMStandardFormat(
        const mex::array<mex::char_t  >& source,
        const mex::array<mex::char_t  >& root,
        std::size_t granularity, std::size_t zeros
        )
    {
        // Ensures backslash at end of root folder.
        std::string base = mex::string(root);
        if ( base.empty() ) { base = "./"; }
        const char last = base[base.size()-1];
        if ((last != '/') && (last != '\\'))
        {
            base += '/';
        }
        const std::string file = mex::string(source);
        std::ifstream in(file.c_str(), std::ios::binary);
        if ( !in.is_open() ) {
            std::ostringstream message;
            message << "Could not open '" << file << "'.";
            throw (std::exception(message.str().c_str()));
        }
        std::size_t i = 0;
        std::size_t done;
        for ( ; in.good() && !in.eof(); ++i )
        {
            const std::size_t length = header(in);
            if ( length == 0 ) {
                mex::warning("End of file found.");
                break;
            }
            // Obtains content length from header.
            std::ostringstream directory;
            directory << folderName(i, granularity, zeros, base);
            if (mex::exist(mex::string(directory.str()))==0.0) {
                mex::mkdir(mex::string(directory.str()));
            }
            std::cout << "'" << fileName(i, granularity, zeros, base) << "' length: " << length << std::endl;
            // Makes sure signature matches.
            char signature[sizeof(Signature)];
            in.read(signature, sizeof(signature));
            if ( std::memcmp(signature, Signature, sizeof(Signature)) != 0 ) {
                throw (std::exception("Out of sync !"));
            }
            // Outputs the file...
            std::ofstream out(fileName(i, granularity, zeros, base).c_str(), std::ios::binary);
            if ( !out.is_open() ) {
                std::ostringstream message;
                message << "Could not create '" << fileName(i, granularity, zeros, base).c_str() << "'." << std::endl;
                throw (std::exception(message.str().c_str()));
            }
            out.write(signature, sizeof(signature));
            
            // Dumps input straight to output.
            const std::size_t bufsize = 8*1024;
            char buffer[bufsize];
            for (done = sizeof(signature);
            ((done < length) && (!in.eof())); ) {
                const std::size_t todo = length - done;
                const std::size_t attempt = std::min(bufsize, todo);
                in.read(buffer, attempt);
                out.write(buffer, in.gcount());
                done += in.gcount();
            }
            // Skips final CR/LF pair.
            if (length == done) {
                in.ignore(2);
            }
            else {
                std::ostringstream message;
                message << "Your last frame is incomplete : " << done << " /" << length << " bytes.";
                mex::warning((message.str()).c_str());
                break;
            }
        }
        

        return (i);
    }

    const char usage[] =
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
      " MJPEGToMStandardFormat(.) - Converts MJPEG file to MStandard Format  \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
      "                                                                      \n"
      " Converts files from MJPEG to MStandard Format                        \n"
      "                                                                      \n"
      " Syntax:                                                              \n"
      "  [] = MJPEGToMStandardFormat ( source, root, callback, granularity, zeros )\n"
      "    ->      source: MJPEG file;                                       \n"
      "    ->        root: the directory in which the frames are saved       \n"
      "    ->    callback: function that checks if a directory exists,       \n"
      "                    and if it doesn't, creates it                     \n"
      "    -> granularity: number of frames in each directory                \n"
      "    ->       zeros: number of zeros in the name of directories.       \n"
      "                    determinates how many frames the video can contain\n"
      "                                                                      \n"
      " Header example :                                                     \n"
      "                                                                      \n"
      "       MStandard Video                                                \n"
      "       number-of-frames : 2101                                        \n"
      "       frames-per-directory : 100                                     \n"
      "       root : videos/test-100                                         \n"
      "                                                                      \n"
      "                                                                      \n"
      " (( Typhaine Giraud   <typhaine.giraud@usherbrooke.ca> ))             \n"
      " (( Andre Louis Caron <andre.louis.caron@usherbrooke.ca> ))           \n"
      ;

}

    /*!
     * @brief Matlab extension entry point.
     *
     * @param nlhs Number of output (left hand-side) variables.
     * @param plhs Output variables.
     * @param nrhs Number of input (right hand-side) variables.
     * @param prhs Input variables.
     */
extern "C" void mexFunction
    ( int nlhs, ::mxArray * plhs[], int nrhs, const ::mxArray * prhs [] )
try
{
        // Displays usage if requested.
    if ((nrhs == 0) || ((nrhs ==1) && (mex::string(prhs[0]) == "--help")))
    {
        throw (std::exception(::usage));
    }
    
        // Sanity check for argument count.
    if ( nrhs != 4 )
    {
        const char message[] =
            "Sorry, wrong argument count (run with '--help').";
        throw (std::exception(message));
    }
    
        // Wraps arguments and invoke main code.
    mex::array< mex::char_t   > source     (prhs[0], mex::clone);
    mex::array< mex::char_t   > root       (prhs[1], mex::clone);
    mex::array< double        > granularity(prhs[2], mex::clone);
    mex::array< double        > zeros      (prhs[3], mex::clone);
    mex::array< double        > frames     (1, 1);
    frames(0) = ::MJPEGToMStandardFormat(source,
        root, std::size_t(granularity(0)), std::size_t(zeros(0)));
    
        // Wraps results.
    if ( nlhs > 0 ) {
        plhs[0] = frames.release();
    }
}
catch ( const std::exception& error ) {
    mex::error(error.what());
}
catch ( ... ) {
    mex::error("Sorry, something unexpected happened, aborting!");
}
