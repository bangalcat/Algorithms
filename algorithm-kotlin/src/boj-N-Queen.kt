var N = 0
var result = 0
var col = IntArray(15)

fun canPut(newR : Int) : Boolean {
    for(r in 0 until newR) {
        if(col[r] == col[newR] || Math.abs(col[newR]-col[r]) == Math.abs(newR-r))
            return false
    }
    return true
}

fun solve(cnt : Int) {
    if(cnt == N)
        result++
    else {
        for(r in 0 until N) {
            col[cnt] = r
            if(canPut(cnt))
                solve(cnt+1)
        }
    }
}

fun main() {
    N = readLine()!!.toInt()
    solve(0)
    println(result)
}