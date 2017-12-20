open Utils;

type state = {
  events: EventData.events,
  loading: bool
};

type action =
  | Loaded(EventData.events)
  | Loading;

let component = ReasonReact.reducerComponent("EventsPage");

let make = (_children) => {
  let loadEvents = ({ReasonReact.reduce}) => {
    EventData.fetchEvents(reduce((payload) => Loaded(payload))) |> ignore;
    reduce(() => Loading, ())
  };
  {
    ...component,
    initialState: () => {events: [||], loading: false},
    reducer: (action, state) =>
      switch action {
      | Loading => ReasonReact.Update({...state, loading: true})
      | Loaded(data) =>
        let updatedEvents = Array.concat([state.events, data]);
        ReasonReact.Update({events: updatedEvents, loading: false})
      },
    didMount: (self) => {
      loadEvents(self);
      ReasonReact.NoUpdate
    },
    render: (self) =>
      <div>
        (
          if (self.state.loading) {
            textEl("Loading")
          } else if (Array.length(self.state.events) > 0) {
            self.state.events |> Array.map(({EventData.title}) => textEl(title)) |> arrayEl
          } else {
            ReasonReact.nullElement
          }
        )
      </div>
  }
};
