// 数据流中的移动平均值
class MovingAverage {
    private int size;
    private Queue<Integer> q;
    private int sum;
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        this.size = size;
        this.sum = 0;
        q = new LinkedList<Integer>();
    }
    
    public double next(int val) {
        q.offer(val);
        if (q.size() > this.size) {
            this.sum -= q.poll();
        }
        this.sum += val;
        return (double)sum / q.size();
    }
}