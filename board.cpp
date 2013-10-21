

class Board {
	private board piece[9][9];

public movePiece(int origin, int destination){
	board[destination] = board[origin];
	board[origin] = NULL;
}

public addPiece(piece newPiece, int location){
	board[location] = newPiece;
}

public removePiece(int location){
	board[location] = NULL;
}

}