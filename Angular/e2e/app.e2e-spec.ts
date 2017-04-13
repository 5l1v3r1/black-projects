import { FirstAngularAppPage } from './app.po';

describe('first-angular-app App', () => {
  let page: FirstAngularAppPage;

  beforeEach(() => {
    page = new FirstAngularAppPage();
  });

  it('should display message saying app works', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('app works!');
  });
});
