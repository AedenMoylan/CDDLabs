//Author: Aeden Moylan
//Date Created: 30/03/2023

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.

#include "Semaphore.h"
#include "Barrier.h"
#include "iostream"

/*! barrier constructor sets the number of threads and the count to zero */
Barrier::Barrier(int numOfThreads)
{
    numThreads = numOfThreads;
    count = 0;
}

/*! threads wait until a barrier has been reached */
void Barrier::wait()
{
    // waiting for other thread
    mutex->Wait();
    // counts number of times threads have passed through
    count++;
    // threads get here when all have finished
    if(count == numThreads)
    {
        barrierTwo->Wait();
        std::cout << " At Barrier " << std::endl;
        // thread can continue
        barrierOne->Signal();
    }
    
    mutex->Signal();
    barrierOne->Wait();
    barrierOne->Signal();

    mutex->Wait();
    count--;
    
    // another check to get the number of times threads pass
    if(count == 0)
    {
        barrierOne->Wait();
        barrierTwo->Signal();
    }
    
    mutex->Signal();
    barrierTwo->Wait();
    barrierTwo->Signal();
}

/*! barrier destructor. deletes mutex, barrierOne, barrierTwo */
Barrier::~Barrier()
{
    delete mutex;
    delete barrierOne;
    delete barrierTwo;
}