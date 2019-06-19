import java.util.*

val board = Array(9){ IntArray(9) }

val chk_row = Array(9) {BooleanArray(10) {false} }
val chk_col = Array(9) {BooleanArray(10) {false} }
val chk_box = Array(9) {BooleanArray(10) {false} }

var findAns = false

fun printBoard(){
    for(i in 0..8){
        board[i].let {
            it.forEach { _i -> print("$_i ") }
        }
        println()
    }
}

fun sudoku() {
    var r = -1
    var c = -1
    for (i in 0..8) {
        for (j in 0..8) {
            if(board[i][j] == 0) {
                r = i
                c = j
                break
            }
        }
        if(r != -1) {
            break
        }
    }

    if(r == -1) {
        findAns = true
        printBoard()
        return
    }

    for(num in 1..9){
        if(!findAns && !chk_row[r][num] && !chk_col[c][num] && !chk_box[cell(r,c)][num]){
            chk_row[r][num] = true
            chk_col[c][num] = true
            chk_box[cell(r,c)][num] = true
            board[r][c] = num
            sudoku()
            board[r][c] = 0
            chk_row[r][num] = false
            chk_col[c][num] = false
            chk_box[cell(r,c)][num] = false
        }
    }
}

fun cell(r : Int, c : Int) : Int{
    return 3 * (r / 3) + (c / 3)
}

fun main(args : Array<String>) = with(Scanner(System.`in`)){
    for(i in 0..8){
        for(j in 0..8){
            board[i][j] = nextInt()
            chk_row[i][board[i][j]] = true
            chk_col[j][board[i][j]] = true
            chk_box[cell(i,j)][board[i][j]] = true
        }
    }
    sudoku()
}