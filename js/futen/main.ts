import Futen, { route } from 'futen';

const Index = route('/')(class {
  public get() {
    return 'Hello World!';
  }
})

new Futen({
  Index
}, { port: 3000 });
