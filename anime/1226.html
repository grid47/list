class DiningPhilosophers {
public:
    mutex mtx[5];
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        unique_lock<mutex> lck1(mtx[left], defer_lock);
        unique_lock<mutex> lck2(mtx[right], defer_lock);
        
        if(philosopher % 2) {
            lck1.lock();
            lck2.lock();
            pickLeftFork();
            pickRightFork();
        } else {
            lck2.lock();
            lck1.lock();
            pickLeftFork();
            pickRightFork();            
        }
        eat();
        putLeftFork();
        putRightFork();
    }
};