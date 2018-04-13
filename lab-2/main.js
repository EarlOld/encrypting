function handleSubmit(event) {
  var text = event.target[0].value;
  var key = Math.floor(+event.target[1].value)
  let rezult = ''
  event.preventDefault();
  if (key <= 0) {
    document.getElementById('rezult').innerText = 'Введіть ключ більший рівний нулю'
  }
  for (let index = 0; index < key; index++) {
    for (let i = index; i < text.length; i += key) {
      rezult +=text[i]
    }
  }
  document.getElementById('rezult').innerText = rezult
}