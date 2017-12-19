open Utils;
type state = {events: EventData.events};

type action =
  | Loaded(EventData.events);

let component = ReasonReact.reducerComponent("EventsPage");

let make = (_children) => {
  let loadEvents = ({ReasonReact.reduce}) =>
    EventData.fetchEvents(reduce(payload => Loaded(payload))) |> ignore;

  {
    ...component,
    initialState: () => {
      events: [||]
    },
    reducer: (action, state) =>
      switch action {
      | Loaded((data)) =>
        let updatedEvents = Array.concat([state.events, data]);
        ReasonReact.Update({
          events: updatedEvents
        })
      },
    didMount: (self) => {
      loadEvents(self);
      ReasonReact.NoUpdate
    },
    render: (self) => {
      <div>
        (
          if (Array.length(self.state.events) > 0) {
            self.state.events
            |> Array.map(({EventData.title}) =>
              textEl(title))
            |> arrayEl
          } else {
            ReasonReact.nullElement
          }
        )
      </div>
    }
  }
};
