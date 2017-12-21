open Utils;

[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (~route, _children) => {
  ...component,
  render: (_self) => {
    let page =
      switch route {
      | Routing.Events => <EventsPage />
      | Routing.AboutUs => <AboutUsPage />
      };

    <div>
      <header>
        <h1> (textEl("Associazione Yume")) </h1>
        <ul>
          <li> <Link currentRoute=route route=Routing.Events href="#/">(textEl("Eventi"))</Link> </li>
          <li> <Link currentRoute=route route=Routing.AboutUs href="#/about-us">(textEl("About Us"))</Link> </li>
        </ul>
      </header>
      <section> page </section>
    </div>
  }
};
