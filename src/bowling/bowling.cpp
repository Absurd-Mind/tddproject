class Bowling {
public:
    int score() {
        int sum = 0;
        
        for (int frame = 0; frame < 10; frame++) {
            sum += first(frame);
            sum += second(frame);
            
            if (isSpare(frame)) {
                sum += firstRollAfterFrame(frame);
            }
            
            if (isStrike(frame)) {
                sum += firstRollAfterFrame(frame);
                sum += secondRollAfterFrame(frame);
            }
        }
        
        return sum;
    }
    
    void roll(int pins) {
        rolls[currentRoll] = pins;
        currentRoll++;
        if (pins == 10) {
            currentRoll++;   
        }
    }
    
private:
    int rolls[24] = {0};
    int currentRoll = 0;
    
    int first(int frame) {
        return rolls[frame * 2];   
    }
    
    int second(int frame) {
        return rolls[frame * 2 + 1];   
    }
    
    bool isStrike(int frame) {
        if (first(frame) == 10) {
            return true;
        }
        return false;
    }
    
    bool isSpare(int frame) {
        if (!isStrike(frame) && first(frame) + second(frame) == 10) {
            return true;   
        }
        return false;
    }
    
    int firstRollAfterFrame(int frame) {
        return first(frame + 1);
    }
    
    /**
     * if next frame is a strike then there is no second throw in the next Frame
     * Take the first roll from the frame after the next frame
     */
    int secondRollAfterFrame(int frame) {
        if (isStrike(frame + 1)) {
            return first(frame + 2);
        } 

        return second(frame + 1);
    }
};
