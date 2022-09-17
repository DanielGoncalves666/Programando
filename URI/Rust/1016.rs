use std::io;

fn main() {
	let handle = io::stdin();
	let mut distancia = String::new();

	handle.read_line(&mut distancia).expect("Falha 1");
	let distancia: i32 = distancia.trim().parse().expect("Falha 2");

	let tempo = distancia * 2;

	println!("{} minutos",tempo);
}