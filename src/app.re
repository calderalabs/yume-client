open Utils;

open ReactRouter;

[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <BrowserRouter>
      <div>
        <header>
          <h1> (textEl("Associazione Yume")) </h1>
          <ul>
            <li> <NavLink exact=true _to="/"> (textEl("Eventi")) </NavLink> </li>
            <li> <NavLink _to="/about-us"> (textEl("About Us")) </NavLink> </li>
          </ul>
        </header>
        <section>
          <Route exact=true path="/" component=(() => <EventsPage />) />
          <Route path="/about-us" component=(() => <AboutUsPage />) />
        </section>
      </div>
    </BrowserRouter>
};
