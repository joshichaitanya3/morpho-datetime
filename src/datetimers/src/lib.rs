use chrono;

#[no_mangle]
pub extern "C" fn local_now() {
    println!("{:?}", chrono::offset::Local::now());
}

#[no_mangle]
pub extern "C" fn utc_now() {
    println!("{:?}", chrono::offset::Utc::now());
}
