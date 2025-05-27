// https://rwx.hashnode.dev/ps2-total-moves-for-bishop

/*

    int mySolution(int a, int b){
        int total = 0;
        
        // bottom left
        total += min(a - 1, b - 1);
        
        // top left
        total += min(a - 1, 8 - b);
        
        // bottom right
        total += min(8 - a, b - 1);
        
        // top right
        total += min(8 - a, 8 - b);
        
        return total;
    }

*/